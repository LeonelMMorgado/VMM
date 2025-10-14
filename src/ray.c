#include <ray.h>
#include <vec3.h>
#include <math.h>

Ray ray_create(Vector3 origin, Vector3 direction) {
    return (Ray){origin, direction};
}

Ray ray_change_origin(Ray ray, Vector3 new_origin) {
    return (Ray){new_origin, ray.direction};
}

Ray ray_change_dir(Ray ray, Vector3 new_direction) {
    return (Ray){ray.origin, new_direction};
}

bool ray_hits_box(Ray ray, Vector3 left_bot_back, Vector3 right_top_front, float *tmin, float *tmax) {
    Vector3 t1 = vec3_div(vec3_sub(left_bot_back, ray.origin), ray.direction);
    Vector3 t2 = vec3_div(vec3_sub(right_top_front, ray.origin), ray.direction);

    Vector3 tmin3 = vec3_float(fminf(t1.x, t2.x), fminf(t1.y, t2.y), fminf(t1.z, t2.z));
    Vector3 tmax3 = vec3_float(fmaxf(t1.x, t2.x), fmaxf(t1.y, t2.y), fmaxf(t1.z, t2.z));

    float tmin_p = fmaxf(fmaxf(tmin3.x, tmin3.y), tmin3.z);
    float tmax_p = fminf(fminf(tmax3.x, tmax3.y), tmax3.z);

    if (tmax_p < 0.0f || tmin_p > tmax_p) return false;

    if (tmin) *tmin = tmin_p;
    if (tmax) *tmax = tmax_p;
    return true;
}

