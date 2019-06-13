#include "Solver.h"
#include <iostream>

using namespace std;

int main()
{
	for (;;)
	{
		double a = 0;
		double b = 0;
		double c = 0;

		if (!(cin >> a))
		{
			break;
		}
		if (!(cin >> b))
		{
			break;
		}
		if (!(cin >> c))
		{
			break;
		}

		try
		{
			auto roots = Solve(a, b, c);
			if (roots.numRoots == 1)
			{
				cout << "Found 1 root: " << roots.roots[0] << endl;
			}
			else if (roots.numRoots == 2)
			{
				cout << "Found 2 roots: " << roots.roots[0] << " " << roots.roots[1] << endl;
			}
		}
		catch (std::exception const& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}
