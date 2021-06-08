#ifdef _WIN32
  #include<windows.h>
#endif  

void scrClean()
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}