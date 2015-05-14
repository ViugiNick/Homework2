digits n = if (n == 0)
              then 0
              else (mod n 10) + digits(div n 10) 