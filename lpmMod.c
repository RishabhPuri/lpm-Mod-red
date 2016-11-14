#include <stdio.h>
#include "redismodule.h"


int lpm_cmd_add (RedisModuleCtx *ctx, RedisModuleString **argv, int argc);
int lpm_cmd_show (RedisModuleCtx *ctx, RedisModuleString **argv, int argc);
int lpm_cmd_delete (RedisModuleCtx *ctx, RedisModuleString **argv, int argc);

int RedisModule_OnLoad(RedisModuleCtx *ctx) 
{
    if (RedisModule_Init(ctx, "lpm", 1, REDISMODULE_APIVER_1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;

    if (RedisModule_CreateCommand(ctx, "lpm.Add", lpm_cmd_add,
                "no-monitor fast", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;
    if (RedisModule_CreateCommand(ctx, "lpm.Show", lpm_cmd_show,
                "no-monitor fast", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;
    if (RedisModule_CreateCommand(ctx, "lpm.Delete", lpm_cmd_delete,
                "no-monitor fast", 1, 1, 1) == REDISMODULE_ERR)
        return REDISMODULE_ERR;
    return REDISMODULE_OK;
}

