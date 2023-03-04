#include <stdio.h>

#include <iostream>
long n, b, r, l, i, vende, rest, ci, arr[100002];
int main() {
  scanf("%ld %ld %ld %ld", &n, &b, &r, &l);
  rest = b;
  for (i = 1; i <= n; i++) {
    arr[i] = 0;
    scanf("%ld", &ci);
    if (ci > l)
      vende = l;
    else
      vende = ci;

    if (rest - vende >= r) {
      rest -= vende;
      arr[i] = vende;
    } else {
      if (rest > r) {
        arr[i] = rest - r;
        rest = r;
      }
    }
  }
  for (i = 1; i < n; i++) printf("%ld ", arr[i]);
  printf("%ld\n", arr[n]);
}
