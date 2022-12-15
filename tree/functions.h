#pragma once
//#include "includes.h"
#include "UIcontrol.h"


void close_onclick(void);
void login_onclick(void);
void register_onclick(void);

void xsh_onclick(void);
void sl_onclick(void);
void gc_onclick(void);

void list_chosen_onclick(int index);
void list_table_onclick(int index);

void add_agent_onclick();
void delete_agent_onclick();
void change_agent_onclick();
void add_department_onclick();
void delete_department_onclick();
void change_department_onclick();

void agent_cancel_onclick();
void agent_confirm_onclick();
void department_cancel_onclick();
void department_confirm_onclick();

void reg_confirm_onclick();
void reg_cancel_onclick();
void get_onclick();

void to_tree_onclick();
void to_manager_onclick();
void backup_onclick();
void retract_onclick();