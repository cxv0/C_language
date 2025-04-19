#ifndef _login_h_
#define _login_h_

#include "user.h"
#include "order.h"

int Judge_Login(char* a, char* p);
int login_fun(INFO (*t)[16]);
void login_page(void);

#endif