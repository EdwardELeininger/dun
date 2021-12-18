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

enum side{
    right,
    left
};

/*
 * base character stats are mind and body, structure of arrays keyed by entity.
 * set functions initialize a character, expanding the array size as needed.
 */

typedef struct StatusBase{
    signed char* mind;
    signed char* body;
    int size;
}status_base;

status_base* status_base_init();

//mind getter and setters
int status_base_mind_get(int entity);
int status_base_mind_set(int entity, signed char value);
int status_base_mind_add(int entity, signed char value);
int status_base_mind_subtract(int entity, signed char value);
int status_base_mind_clear(int entity);
//body getter and setters
int status_base_body_get(int entity);
int status_base_body_set(int entity, signed char value);
int status_base_body_add(int entity, signed char value);
int status_base_body_subtract(int entity, signed char value);
int status_base_body_clear(int entity);

/* TODO
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
    int size;
}status_body;
*/

/*
 * abstract statuses
 */
typedef struct StatusAbstract{
    signed int* stamina;
    signed int* will;
    int size;
}status_abstract;

status_abstract* status_abstract_init();
//stamina getter and setters
int status_abstract_stamina_get(int entity);
int status_abstract_stamina_get_max(int entity);
int status_abstract_stamina_set(int entity, int value);
int status_abstract_stamina_add(int entity, int value);
int status_abstract_stamina_subtract(int entity, int value);
int status_abstract_stamina_clear(int entity);
//will getter and setters
int status_abstract_will_get(int entity);
int status_abstract_will_get_max(int entity);
int status_abstract_will_set(int entity, int value);
int status_abstract_will_add(int entity, int value);
int status_abstract_will_subtract(int entity, int value);
int status_abstract_will_clear(int entity);




typedef struct StatusMisc{
    signed char* weight;
    signed char* carry_cap;
}status_misc;

enum damage_state{
    fine,
    injured,
    disabled,
    ruined
};

/*TODO
 * guard and strike
 * different guards are better at different things.
 * strike
 * -over
 * -under
 * -side
 * -offside
 * -thrust
 * blocking
 * -block: uses the most stamina, but has the highest success rate, put's the users gear at risk though.
 * -parry: a balanced approch, minimal stamina, minimal equip damage, good success rate.
 * -catch: attempt to pin or grab the oppenent's weapon/arm. high risk, high reward
 * -reposte: counter with a thrust, low succes rate, high reward.
 * feinght
 * dodge
 *
 *  the ranking triangle is 
 *  -reach
 *  -power
 *  -balance
 *
 *  lastly is guards/stances
 *  -high
 *  -low
 *  -mid/plow
 *  -long/point
 *  -back/fool
 *
 *  the game is to predict your oppenent, pick a good guard, anticipate his strike, and make one of your own.
 *  a "move" consists of a starting stance held over from the last round, a reaction (block, feign, dodge/step), a strike, and a closing guard.
 *  different opening amd closing guards mean differentrankings. e.g a perry from high guard and an over strie into low guard would be strong against a high strikes but the strike would most likely fail against a low one.
 */

#endif
