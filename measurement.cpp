/**
 * 09.03.2020
 * measurement
 * 
 * @author havlong 
 * @version 1.0
 */

#include "measurement.h"

long long measureAction(const std::function<void()>& action) {
    auto start = std::chrono::steady_clock::now();
    action();
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start).count();
}