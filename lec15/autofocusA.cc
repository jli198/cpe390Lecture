uint64_t focus = 0;
for (j = 0 to h-1)
  for(i = 0 to w-1)
    focus += abs((pixel(i,j) - pixel(i-1, j)));
      abs((pixel(i,j)-pixel(i,j-1)));
  end;
end;
    