# Giant Step Baby Step

Usado para investigar um espaço em módulo de uma forma mais rápida. Segue um exemplo:

`z^E == y % m`, com m primo e 0 <= E < m (teorema de Fermat consegue fazer a limitação)

Então podemos reescrever como:

`z^(x*a + b) == y % m`, a = sqrt(m) e 0 <= b <= a. 

Isso é garantido manter a solução, pois cobre todos os valores de 0 a m. Sendo assim, podemos continuar:

`z^(x*a) * z^b == y % m` =>
`z^(x*a) % m == (y * z^b) % m`

Ao gravar os (y * z^b) possíveis, O(sqrt(m)), é possível fazer uma busca binária para gerar o igualdade.

```c++
int gsbs (int m, int y, int z) {
  int a = sqrt(m);
  map<int, int> v;

  v[0] = y % m;
  for (int i = 1; i <= a; i++)
    v[i] = (v[i-1] * z) % m;

  int aux = pow(z, a), ini = 1;

  for (int i = 0; i <= a; i++, ini *= aux)
    if (v.count(ini % m))
      return m[ini%m];

  return -1;
}
```

OBS: Complexidade de O(sqrt(m) * log(sqrt(m)))
