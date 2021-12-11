#ifndef COMBAT_STATS_H
#define COMBAT_STATS_H
//bylateral semetry is annoying, why can't we just have one arm to keep track of...


enum target{
    head,
    neack,
    shoulder,
    torso,
    pelvis,
    upper_arm,
    lower_arm,
    hand,
    thigh,
    shin,
    foot
};
// maybe?

enum side{
    right,
    left
};

/* alright, how's this data gonna look...
 * array body[entity][part][semetry]
 * ohh... maybe i'm taking the wrong approach
 * struct body->parts[entity][semetry]
 */

typedef struct StatusBase{
    signed char* mind;
    signed char* body;
}status_base;
typedef struct StatusBody{
    char* head;
    char* torso;
    char* pelvis;
    char* upper_arm[2];
    char* lower_arm[2];
    char* hand[2];
    char* thigh[2];
    char* shin[2];
    char* foot[2];
}status_body;
typedef struct StatusAbstract{
    unsigned int* stamina;
    unsigned int* will;
}status_abstract;
typedef struct StatusMisc{
    unsigned char* weight;
    unsigned char* carry_cap;
}status_misc;

enum damage_state{
    fine,
    injured,
    disabled,
    ruined
};

stats* init_stats();
set_stats(int entity, signed char body, signed char mind);
clear_stats(int entity);
#endif
