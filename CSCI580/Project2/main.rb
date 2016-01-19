#!/usr/bin/ruby

# Read in description and split it into words
csciDesc = File.read('CSCI_Learn_File.txt').split("\n")
mathDesc = File.read('MATH_Learn_File.txt').split("\n")
civlDesc = File.read('CIVL_Learn_File.txt').split("\n")
biolDesc = File.read('BIOL_Learn_File.txt').split("\n")
relsDesc = File.read('RELS_Learn_File.txt').split("\n")
csciNumDesc = csciDesc.size
mathNumDesc = mathDesc.size
civlNumDesc = civlDesc.size
biolNumDesc = biolDesc.size
relsNumDesc = biolDesc.size
csciDesc = File.read('CSCI_Learn_File.txt').split(/\W+/)
mathDesc = File.read('MATH_Learn_File.txt').split(/\W+/)
civlDesc = File.read('CIVL_Learn_File.txt').split(/\W+/)
biolDesc = File.read('BIOL_Learn_File.txt').split(/\W+/)
relsDesc = File.read('RELS_Learn_File.txt').split(/\W+/)

# Read in description from user
userDesc = File.read(ARGV[0]).split(/\W+/)
userDesc = userDesc.uniq

# init laplace smoothing value and number of classes
k = 1
cl = 5

# Count the occurances of each words
csciCount = Array.new
tmpIndiv = Array.new
# init csciCount
i = 0
csciDesc.each do |x|
  if tmpIndiv.index(x)
    j = tmpIndiv.index(x)
    csciCount[j] = csciCount[j]+1
  else
    csciCount[i] = 1;
    tmpIndiv.push(x)
    i = i + 1
  end
end
csciDesc = csciDesc.uniq

# init mathCount
mathCount = Array.new
tmpIndiv = Array.new
i = 0
mathDesc.each do |x|
  if tmpIndiv.index(x)
    j = tmpIndiv.index(x)
    mathCount[j] = mathCount[j]+1
  else
    mathCount[i] = 1;
    tmpIndiv.push(x)
    i = i + 1
  end
end
mathDesc = mathDesc.uniq

# init civlCount
civlCount = Array.new
tmpIndiv = Array.new
i = 0
civlDesc.each do |x|
  if tmpIndiv.index(x)
    j = tmpIndiv.index(x)
    civlCount[j] = civlCount[j]+1
  else
    civlCount[i] = 1;
    tmpIndiv.push(x)
    i = i + 1
  end
end
civlDesc = civlDesc.uniq

# init biolCount
biolCount = Array.new
tmpIndiv = Array.new
i = 0
biolDesc.each do |x|
  if tmpIndiv.index(x)
    j = tmpIndiv.index(x)
    biolCount[j] = biolCount[j]+1
  else
    biolCount[i] = 1;
    tmpIndiv.push(x)
    i = i + 1
  end
end
biolDesc = biolDesc.uniq

# init relsCount
relsCount = Array.new
tmpIndiv = Array.new
i = 0
relsDesc.each do |x|
  if tmpIndiv.index(x)
    j = tmpIndiv.index(x)
    relsCount[j] = relsCount[j]+1
  else
    relsCount[i] = 1;
    tmpIndiv.push(x)
    i = i + 1
  end
end
relsDesc = relsDesc.uniq

dictionary = relsDesc+civlDesc+biolDesc+csciDesc+mathDesc
dictionary = dictionary.uniq

probCSCI = (csciNumDesc+k).to_f/((csciNumDesc+mathNumDesc+civlNumDesc+biolNumDesc+relsNumDesc)+(k*cl)).to_f
probMATH = (mathNumDesc+k).to_f/((csciNumDesc+mathNumDesc+civlNumDesc+biolNumDesc+relsNumDesc)+(k*cl)).to_f
probCIVL = (civlNumDesc+k).to_f/((csciNumDesc+mathNumDesc+civlNumDesc+biolNumDesc+relsNumDesc)+(k*cl)).to_f
probBIOL = (biolNumDesc+k).to_f/((csciNumDesc+mathNumDesc+civlNumDesc+biolNumDesc+relsNumDesc)+(k*cl)).to_f
probRELS = (relsNumDesc+k).to_f/((csciNumDesc+mathNumDesc+civlNumDesc+biolNumDesc+relsNumDesc)+(k*cl)).to_f

dictionarySize = dictionary.size

# Calculate P(userWord | csci)
# puts "\nCalculate P(userWord | csci)", "-"*50
userProbCSCI = Array.new
userDesc.each do |x|
  if(csciDesc.index(x))
    tmp = (csciCount[csciDesc.index(x)]+k).to_f/(csciDesc.size+(k*dictionarySize)).to_f
  else
    tmp = k.to_f/(csciDesc.size+(k*dictionarySize)).to_f
  end
  userProbCSCI.push(tmp)
  # puts "P(#{x}|csci) = #{tmp}"
end

# Calculate P(userWord | math)
# puts "\nCalculate P(userWord | math)", "-"*50
userProbMATH = Array.new
userDesc.each do |x|
  if(mathDesc.index(x))
    tmp = (mathCount[mathDesc.index(x)]+k).to_f/(mathDesc.size+(k*dictionarySize)).to_f
  else
    tmp = k.to_f/(mathDesc.size+(k*dictionarySize)).to_f
  end
  userProbMATH.push(tmp)
  # puts "P(#{x}|math) = #{tmp}"
end

# Calculate P(userWord | civl)
# puts "\nCalculate P(userWord | civl)", "-"*50
userProbCIVL = Array.new
userDesc.each do |x|
  if(civlDesc.index(x))
    tmp = (civlCount[civlDesc.index(x)]+k).to_f/(civlDesc.size+(k*dictionarySize)).to_f
  else
    tmp = k.to_f/(civlDesc.size+(k*dictionarySize)).to_f
  end
  userProbCIVL.push(tmp)
  # puts "P(#{x}|civl) = #{tmp}"
end

# Calculate P(userWord | biol)
# puts "\nCalculate P(userWord | biol)", "-"*50
userProbBIOL = Array.new
userDesc.each do |x|
  if(biolDesc.index(x))
    tmp = (biolCount[biolDesc.index(x)]+k).to_f/(biolDesc.size+(k*dictionarySize)).to_f
  else
    tmp = k.to_f/(biolDesc.size+(k*dictionarySize)).to_f
  end
  userProbBIOL.push(tmp)
  # puts "P(#{x}|biol) = #{tmp}"
end

# Calculate P(userWord | rels)
# puts "\nCalculate P(userWord | rels)", "-"*50
userProbRELS = Array.new
userDesc.each do |x|
  if(relsDesc.index(x))
    tmp = (relsCount[relsDesc.index(x)]+k).to_f/(relsDesc.size+(k*dictionarySize)).to_f
  else
    tmp = k.to_f/(relsDesc.size+(k*dictionarySize)).to_f
  end
  userProbRELS.push(tmp)
  # puts "P(#{x}|rels) = #{tmp}"
end

# Calculate P(userDesc | csci)
probDescCSCI = 0
userProbCSCI.each do |x|
  if probDescCSCI == 0
    probDescCSCI = x
  else
    probDescCSCI = probDescCSCI * x
  end
end

# Calculate P(userDesc | math)
probDescMATH = 0
userProbMATH.each do |x|
  if probDescMATH == 0
    probDescMATH = x
  else
    probDescMATH = probDescMATH * x
  end
end

# Calculate P(userDesc | civl)
probDescCIVL = 0
userProbCIVL.each do |x|
  if probDescCIVL == 0
    probDescCIVL = x
  else
    probDescCIVL = probDescCIVL * x
  end
end

# Calculate P(userDesc | biol)
probDescBIOL = 0
userProbBIOL.each do |x|
  if probDescBIOL == 0
    probDescBIOL = x
  else
    probDescBIOL = probDescBIOL * x
  end
end

# Calculate P(userDesc | rels)
probDescRELS = 0
userProbRELS.each do |x|
  if probDescRELS == 0
    probDescRELS = x
  else
    probDescRELS = probDescRELS * x
  end
end

# puts probDescMATH, "  ", probDescCSCI, "  ", probDescCIVL, "  ", probDescBIOL, "  ", probDescRELS

# Calculate P(csci | userDesc)
probCSCIDesc = (probDescCSCI*probCSCI)/((probDescCSCI*probCSCI)+(probDescMATH*probMATH)+(probDescCIVL*probCIVL)+(probDescBIOL*probBIOL)+(probDescRELS*probRELS))

# Calculate P(math | userDesc)
probMATHDesc = (probDescMATH*probMATH)/((probDescCSCI*probCSCI)+(probDescMATH*probMATH)+(probDescCIVL*probCIVL)+(probDescBIOL*probBIOL)+(probDescRELS*probRELS))

# Calculate P(civl | userDesc)
probCIVLDesc = (probDescCIVL*probCIVL)/((probDescCSCI*probCSCI)+(probDescMATH*probMATH)+(probDescCIVL*probCIVL)+(probDescBIOL*probBIOL)+(probDescRELS*probRELS))

# Calculate P(civl | userDesc)
probBIOLDesc = (probDescBIOL*probBIOL)/((probDescCSCI*probCSCI)+(probDescMATH*probMATH)+(probDescCIVL*probCIVL)+(probDescBIOL*probBIOL)+(probDescRELS*probRELS))

# Calculate P(rels | userDesc)
probRELSDesc = (probDescRELS*probRELS)/((probDescCSCI*probCSCI)+(probDescMATH*probMATH)+(probDescCIVL*probCIVL)+(probDescBIOL*probBIOL)+(probDescRELS*probRELS))

puts "P(math | userDesc): ", probMATHDesc
puts "P(csci | userDesc): ", probCSCIDesc
puts "P(civl | userDesc): ", probCIVLDesc
puts "P(biol | userDesc): ", probBIOLDesc
puts "P(rels | userDesc): ", probRELSDesc

mins = [probMATHDesc, probCSCIDesc, probBIOLDesc, probCIVLDesc, probRELSDesc]
min = mins.sort.last

if min == probMATHDesc
  puts "Given description is from the MATH department"
elsif min == probCSCIDesc
  puts "Given description is from the CSCI department"
elsif min == probBIOLDesc
  puts "Given description is from the BIOL department"
elsif min == probCIVLDesc
  puts "Given description is from the CIVL department"
elsif min == probRELSDesc
  puts "Given description is from the RELS department"
end
