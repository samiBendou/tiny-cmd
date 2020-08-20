/**
 * @file cmd.h
 * @author Sami Dahoux (s.dahoux@emse.fr)
 * @brief Command parsing module featuring options
 */

#ifndef TINY_CMD_CMD_H
#define TINY_CMD_CMD_H

#include <math.h>
#include <cmd/consts.h>
#include <cmd/io.h>
#include <cmd/opt.h>
#include <cmd/descr.h>


typedef struct
{
	char name[CMD_LINE_LEN];
	CMD_opt_t options[CMD_MAX_OPTS];
} CMD_cmd_t;

typedef CMD_err_t *(*CMD_action_t)(const CMD_cmd_t *cmd);

typedef struct
{
	char name[CMD_LINE_LEN];
	CMD_action_t action;
} CMD_hook_t;

CMD_cmd_t CMD_cmd(char *name);

void CMD_cmd_reset(CMD_cmd_t *cmd);

CMD_cmd_t *CMD_cmd_copy(CMD_cmd_t *dst, const CMD_cmd_t *src);

CMD_err_t *CMD_cmd_parse(CMD_cmd_t *cmd, char *str, const CMD_descr_tab_t *tab);

CMD_hook_t CMD_hook(char *name, CMD_action_t action);

void CMD_hook_reset(CMD_hook_t *hook);

int CMD_hook_find(const CMD_hook_t hooks[], size_t len, const char *name);

CMD_err_t *CMD_parse_opt(CMD_opt_t *opt, const CMD_descr_opt_t *descr, char *word, size_t len);

CMD_err_t *CMD_parse_opts(CMD_opt_t opts[], const CMD_descr_cmd_t *descr, char *words[], size_t len);

int CMD_check_excl(const CMD_opt_t opts[], const CMD_descr_cmd_t *descr);

int CMD_check_optl(const CMD_opt_t opts[], const CMD_descr_cmd_t *descr);

CMD_err_t *CMD_run(const CMD_descr_tab_t *tab, const CMD_hook_t hooks[]);

#endif //TINY_CMD_CMD_H
