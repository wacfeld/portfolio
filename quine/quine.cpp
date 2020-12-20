#include <iostream>
int main()
{
	std::string x[] = {"#include <iostream>\nint main()\n{\n    std::string x[] = {", "};\n    std::cout << x[0] << \"\\\"\" << x[0] << \"\\\", \\\"\" << x[1] << \"\\\"\";\n    std::cout << x[1];\n}\n"};
	std::cout << x[0] << "\"" << x[0] << "\", \"" << x[1] << "\"";
	std::cout <<  x[1];
}
