#include "../00-LIB/STD_TYPES.h"

typedef struct
{
	/*PID constants*/
	f32 Kp;
	f32 Ki;
	f32 Kd;
	
	/*Output limits*/
	f32 Max_Limit;
	f32 Min_Limit;
	
	/*Integrator Limits*/
	f32 Max_Integrator_Limit;
	f32 Min_Integrator_Limit;
	
	/*Sampling Time*/
	f32 Sampling_Time;
	
	/*Low pass Filter time constant */
	f32 Tau;
	
	/*Previous Reading*/
	f32 prevMeasurement;		/* Required for differentiator */
	f32 prevError;			/* Required for integrator */
	/*****************/
	f32 differentiator;
	f32   Integrator;

	f32 output;
}PID_control;

void PID_init(PID_control * pid );
f32 PID_controller_calc(PID_control *pid, f32 setpoint ,f32 RT_measurment);
