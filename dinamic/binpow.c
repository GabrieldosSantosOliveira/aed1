#include <stdio.h>
typedef long long int ll;
ll binPow(ll base, ll expoente)
{
  ll valor = 1;
  ll potencia = base;
  while (expoente != 0)
  {
    if (expoente % 2 == 1)
    {
      valor *= potencia;
    }
    potencia *= potencia;
    expoente = expoente / 2;
  }
  return valor;
}

int main()
{
  ll a = binPow(2, 40);

  printf("%lli\n", a);
  return 0;
}