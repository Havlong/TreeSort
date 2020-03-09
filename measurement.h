/**
 * 09.03.2020
 * measurement
 * 
 * @author havlong 
 * @version 1.0
 */

#ifndef TREESORT_MEASUREMENT_H
#define TREESORT_MEASUREMENT_H

#include <functional>
#include <chrono>

long long measureAction(const std::function<void()>& action);

#endif //TREESORT_MEASUREMENT_H
