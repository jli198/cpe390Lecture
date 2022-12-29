#include <cstdint>

int64_t dot(uint32_t* a, uint32_t* b, uint32_t len){
	int64_t s=0;
	for(int i = 0; i < len; i++){
		s += a[i]*b[i];
	}
	return s;
}

int main(){}
