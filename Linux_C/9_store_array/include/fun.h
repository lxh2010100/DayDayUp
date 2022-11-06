#ifndef __FUN__
#define __FUN__
#include <stdbool.h>
#include "arr.h"

bool init_array(struct arry_info *parry, int max);
bool is_empty(struct arry_info *parry);
bool is_full(struct arry_info *parry);
bool append_array(struct arry_info *parry, int var);
bool show_array(struct arry_info *parry);
bool insert_array(struct arry_info *parry, int position, int var);
bool delete_array(struct arry_info *parry, int position);
bool change_array(struct arry_info *parry, int position, int var);
bool find_array(struct arry_info *parry, int var);
bool sort_array(struct arry_info *parry);
#endif