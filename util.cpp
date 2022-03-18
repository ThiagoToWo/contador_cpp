#include <string>
using std::string;

bool is_upper(char ch) {
	return bool(ch >= 'A' && ch <= 'Z');
}

bool is_lower(char ch) {
	return bool(ch >= 'a' && ch <= 'z');
}

bool is_letter(char ch) {
	return bool(is_upper(ch) || is_lower(ch));
}

void reduce(string& s) {
	while (s.length() > 0 && !is_letter(s[0])) {
		s.erase(0, 1);
	}
	
	int k = s.length() - 1;
	
	while (k > 0 && !is_letter(s[k])) {
		s.erase(k, 1);
		k--;
	}
	
	int len = s.length();
	
	if (len == 0) return;
	
	for (int i = 0; i < len; i++) {
		if (is_upper(s[i])) {
			s[i] += 'a' - 'A';
		}
	}
}