BEGIN {
  FS="\t"
  printf("%-30s","Item");
  printf("Cost\n");
  printf("%-30s","====");
  printf("======\n");
}

{
  printf("%-30s",$2);
  printf($3);
  printf("\n");
  sub(/\$/, "", $3)
  categories[$1]+=$3;
}


END {
  printf("\nSubtotal by Category\n");
  printf("---------------------------\n");
  total=0;
  for (var in categories) {
    printf("%-20s",var);
    printf("$");
    printf("%6.2f",categories[var]);
    printf("\n");
    total+=categories[var];
  }
  printf("===========================\n");
  printf("%-20s","TOTAL");
  printf("$");
  printf("%.2f",total);
  printf("\n");
}
