#ifndef __HR_ANALYZER_H_
#define __HR_ANALYZER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define HR_ANALYZER_EMPTY		0.0f
#define HR_ANALYZER_ERRROR		-1.0f

typedef enum {
	LOCAL_EXTM_IDLE,
	LOCAL_EXTM_STARTED,
	LOCAL_EXTM_FOUND		// found before oposite local extrema
} extrema_state_t;

typedef struct pulsomteter {

	int32_t prev_sample_val;

	int32_t local_max_val;
	extrema_state_t local_max_state;

	int32_t local_min_val;
	extrema_state_t local_min_state;

	int32_t hysteresis;
	const int32_t hysteresis_div;

	int32_t beat_threshold;
	int64_t prev_beat_ts;

	const float heart_rate_max_val;
	const float heart_rate_min_val;

	float heart_rate_val;

} hr_analyzer_st;

hr_analyzer_st *hr_analyzer_init(int32_t hysteresis_div);
void hr_analyzer_deinit(hr_analyzer_st *hr_analyzer);

float hr_analyzer_check_for_beat(hr_analyzer_st *hr_analyzer, int32_t new_sample_val,
		uint32_t current_time_ms);

#endif /* __HR_ANALYZER_H_ */
