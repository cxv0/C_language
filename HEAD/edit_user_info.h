#ifndef _edit_user_info_h_
#define _edit_user_info_h_

void create_user_info(char *account);
void add_user_info(char *account, info *ip, char *item_name, int *item_time, int *item_status, long *item_code);
void edit_user_info(char *account, info *ip, char *item_name, int *item_time, int *item_status, long *item_code, int number);

#endif