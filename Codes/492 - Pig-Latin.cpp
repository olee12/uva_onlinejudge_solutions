#include <stdio.h>
#include <ctype.h>
bool test(char ch);

int main()
{
  int i, j;
  char ch;
  char root;
  bool s;
  while (true)
  {
      i = 0;
      while (true)
      {
          ch = getchar();

          if (ch == EOF)
              return 0;

          if (isalpha(ch))
          {
              if (!i)
              {
                  s = test(ch);
                  if (s)
                      printf("%c", ch);
                  else
                      root = ch;

                  i++;
              }
              else
                  printf("%c", ch);
          }

          else
          {
              if (!i)
              {
                  printf("%c", ch);
                  break;
              }

              if (s)
                  printf("ay%c", ch);
              else
                  printf("%cay%c", root, ch);

              break;
          }
      }

  }

  return 0;
}

bool test(char ch)
{
  if (ch == 'A' || ch == 'a')
      return true;
  if (ch == 'E' || ch == 'e')
      return true;
  if (ch == 'I' || ch == 'i')
      return true;
  if (ch == 'O' || ch == 'o')
      return true;
  if (ch == 'U' || ch == 'u')
      return true;

  return false;
}
