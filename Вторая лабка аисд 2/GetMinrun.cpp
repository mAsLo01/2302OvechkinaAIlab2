int GetMinrun(int len)
{
	int r = 0;
	while (len >= 64) {
		r |= len & 1;
		len >>= 1;
	}
	return len + r;
}