/*We want make a package of goal kilos of chocolate. We have small bars (1 kilo each) and big bars (5 kilos each). Return the number of small bars to use, assuming we always use big bars before small bars. Return -1 if it can't be done.*/

/*
makeChocolate(4, 1, 9) → 4
makeChocolate(4, 1, 10) → -1
makeChocolate(4, 1, 7) → 2
*/

/*****************Solution***********************/

public int makeChocolate(int small, int big, int goal) {
  int rem = goal % 5;
  if (small + (big*5) < goal)
    return -1;
  else if (rem <= small && goal - big*5 > 4)
    return rem + 5;
  else if (rem <= small)
    return rem;
  else
    return -1;
}

  
  
