#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H

/*You can choose from these options:
 * 	MNVIC_GROUP4_SUB0		  ---->			   You can access 4 bits to make groups only
 * 	MNVIC_GROUP3_SUB1         ---->            You can access 3 bits to make groups and 1 bit to subgroup
 * 	MNVIC_GROUP2_SUB2         ---->            You can access 2 bits to make groups and 2 bits to subgroup
 * 	MNVIC_GROUP1_SUB3         ---->            You can access 1 bits to make groups and 3 bits to subgroup
 * 	MNVIC_GROUP0_SUB4         ---->            You can access 4 bits to make subgroups only
 * */

#define MNVIC_GROUP_SUB_DISTRIBUTION		MNVIC_GROUP2_SUB2

#endif
