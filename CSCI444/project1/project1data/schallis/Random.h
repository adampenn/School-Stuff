#ifndef _RANDOM_H
#define _RANDOM_H

class Random {
	public:
		Random(int low, int high);
		int get(void) const;
	private:
		int low;
		int diff;
		static void seed(void);
		static int seedcount;
};
#endif
