#include "xorshift.hpp"

#include <limits>


static const my::xorshift::state_type s_default_seed = {
    123456789, 362436069, 521288629, 88675123
};

my::xorshift::xorshift(void)
    : state_(s_default_seed)
{}

my::xorshift::xorshift(const state_type &seed)
    : state_(seed)
{}

my::xorshift::xorshift(result_type r)
    : state_({s_default_seed.x, s_default_seed.y, s_default_seed.z, r})
{}

my::xorshift::xorshift(std::random_device &rd)
	: state_({rd(), rd(), rd(), rd()})
{}

void my::xorshift::seed(const state_type &seed) {
    state(seed);
}

void my::xorshift::seed(void) {
    state(s_default_seed);
}

void my::xorshift::seed(result_type r) {
    auto seed = s_default_seed;
    seed.w = r;
    state(seed);
}

void my::xorshift::seed(std::random_device &rd) {
	state({ rd(), rd(), rd(), rd() });
}

void my::xorshift::discard(unsigned long long z) {
    while (z--)
        (*this)();
}

const my::xorshift::state_type &my::xorshift::state(void) const {
    return state_;
}

void my::xorshift::state(const state_type &state) {
    state_ = state;
}

my::xorshift::result_type my::xorshift::min(void) {
    return std::numeric_limits<result_type>::min();
}

my::xorshift::result_type my::xorshift::max(void) {
    return std::numeric_limits<result_type>::max();
}

my::xorshift::result_type my::xorshift::operator()(void) {
    result_type t = state_.x ^ (state_.x << 15);
    state_.x = state_.y; state_.y = state_.z; state_.z = state_.w;
    return state_.w = state_.w ^ (state_.w >> 21) ^ (t ^ (t >> 4));
}

bool my::xorshift::operator==(const xorshift& other)
{
	return state_.w == other.state_.w
		&& state_.x == other.state_.x
		&& state_.y == other.state_.y
		&& state_.z == other.state_.z;
}

bool my::xorshift::operator!=(const xorshift& other)
{
	return !(*this == other);
}

//bool my::operator==(const xorshift &lhs, const my::xorshift &rhs) {
//	return lhs.x == rhs.x
//		&& lhs.y == rhs.y
//		&& lhs.z == rhs.z
//		&& lhs.w == rhs.w;
//}
//
//bool my::operator!=(const my::xorshift &lhs, const my::xorshift &rhs) {
//	return lhs.x != rhs.x
//		|| lhs.y != rhs.y
//		|| lhs.z != rhs.z
//		|| lhs.w != rhs.w;
//}
