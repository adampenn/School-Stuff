#!/usr/bin/ruby

input = IO.readlines('input_hw7.txt').map {|i| i.split.map(&:to_i)}
distance = Array.new
labels = IO.readlines('class_label.txt').map{|i| i.to_i}
p = 2;
q = [4, 3, 2];

input.each { |i|
  sums = Array.new
  for j in 0..2
    sums[j] = (q[j]- i[j])**p
  end
  sum = 0;
  sums.each { |j|
    sum = sum + j
  }
  sum = Math.sqrt(sum)
  distance.push(sum)
}

for i in 0..distance.size-1
  distance[i] = [distance[i], labels[i]]
end

distance = distance.sort {|a,b| a[0] <=> b[0]}

min = Array.new
for i in 0..4
  min.push(distance[i])
end

puts min.inspect
