#include <iostream>
using namespace std;

//THIS PACK FUNCTION IS RIGHT
uint64_t pack(const uint32_t in[], uint32_t len,	uint64_t out[]) {

for (int j = 0; j < ((len / 32) + 1); j++) {
    uint64_t ans = 0;
    for (int i = (32 * j); i < ((32 * j) + 32); i++) {
      ans = ans << 2;
      ans = ans | in[i];
    }
    out[j] = ans;
  }
  return ((len / 32 + 1));
}

int main() {
  const uint32_t input_size = 1036;
	uint32_t* p = new uint32_t[input_size];
	for (uint32_t i = 0; i < input_size; i++)
		p[i] = i & 3; // write numbers from 0..3 into each array element

	// allocate enough 64-bit numbers to hold the output
	uint64_t*out = new uint64_t[(input_size+31) / 32];
															
	uint64_t out_len = pack(p, input_size, out);
	for (uint32_t i = 0; i < out_len; i++) {
		cout << hex << out[i] << '\n';
	}
}