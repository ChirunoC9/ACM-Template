#include <bits/stdc++.h>

namespace Royal_Guard::IO {
	struct Fread {
		char *p1, *p2, buf[100000];
		constexpr char nextchar() noexcept {
			return (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++);
		}
		template <class T> constexpr void read(T &val) noexcept {
			val = 0;
			int f = 1;
			char ch = nextchar();
			while (ch < 48 || ch > 57) {
				if (ch == '-') {
					f = -1;
				}
				ch = nextchar();
			}
			while (ch >= 48 && ch <= 57) {
				val = val * 10 + ch - 48, ch = nextchar();
			}
			val *= f;
		}
		template <class T> constexpr Fread& operator >> (T &val) noexcept {
			this->read(val);
			return *this;
		}
	} fin;

	struct Fwrite {
		template <class T> constexpr void write(T x) {
			if (x < 0) {
				putchar('-');
				x = -x;
			}
			if (x > 9)
				write(x / 10);
			putchar(x % 10 + '0');
		}
		constexpr void write(char x) { putchar(x); }
		constexpr void write(const char *x) { puts(x); }
		// constexpr void write(const std::string &str) { puts(str.c_str()); }
		template <class T> constexpr Fwrite& operator << (const T &x) {
			this->write(x);
			return *this;
		}
	} fout;
}