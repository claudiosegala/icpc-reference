# Math

## Euler

`a^phi(m) == 1 % m, se gcd(a, m) == 1`

### Fermat

Se m é primo, temos que `phi(m) == m-1`

## Propriedades de Módulo

### Redução por Divisor Comum

`(a * c) == (b * c) % n` =>
`a == b % (n / d), d = gcd(n, c)`

### Redução de potência

`a^n == b % m` =>
`(a^m)^(n/m) * a^(n%m) == b % m` =>
`a^(n/m) * a^(n%m) == b % m` =>

## Wilson

`(p - 1)! == -1 % p, se p primo`

p é primo => `x^2 == a % p`, isso tem duas soluções ou nenhuma (x_0 ou p - x_0)
p é primo ímpar => `x^2 == 1 % p`, isso tem duas soluções (x_0 = 1 e x_1 = -1)

## Símbolo de Legendre

[TODO]

## Reciprocidade Quadrática

[TODO]
