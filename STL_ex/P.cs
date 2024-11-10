using System;
class STL
{
	static void Main(string[] args)
	{
		int i = int.Parse(Console.ReadLine());
		char oper;
		string str = Console.ReadLine();
		string[] arr = str.Split();
		oper = char.Parse(arr[0]);
		string expression = "";
		int num1 = int.Parse(arr[1]);
		int num2 = int.Parse(arr[2]);
		int result = 0;

		switch (oper)
		{
			case 'a':
				result = num1 + num2;
				expression = $"{num1}+{num2}={result}";
				break;
			case 'b':
				result = num1 - num2;
				expression = $"{num1}-{num2}={result}";
				break;
			case 'c':
				result = num1 * num2;
				expression = $"{num1}*{num2}={result}";
				break;
		}

		Console.WriteLine(expression);
		Console.WriteLine(expression.Length);

		for (int j = 0; j < i - 1; j++)
		{
			string str1 = Console.ReadLine();
			string[] arr1 = str1.Split();

			if (arr1.Length == 3)
			{
				oper = char.Parse(arr1[0]);
				int num11 = int.Parse(arr1[1]);
				int num22 = int.Parse(arr1[2]);
				int result1 = 0;
				string expression1 = "";

				switch (oper)
				{
					case 'a':
						result1 = num11 + num22;
						expression1 = $"{num11}+{num22}={result1}";
						break;
					case 'b':
						result1 = num11 - num22;
						expression1 = $"{num11}-{num22}={result1}";
						break;
					case 'c':
						result1 = num11 * num22;
						expression1 = $"{num11}*{num22}={result1}";
						break;
				}
				Console.WriteLine(expression1);
				Console.WriteLine(expression1.Length);
			}
			else
			{
				int num11 = int.Parse(arr1[0]);
				int num22 = int.Parse(arr1[1]);
				int result1 = 0;
				string expression1 = "";

				switch (oper)
				{
					case 'a':
						result1 = num11 + num22;
						expression1 = $"{num11}+{num22}={result1}";
						break;
					case 'b':
						result1 = num11 - num22;
						expression1 = $"{num11}-{num22}={result1}";
						break;
					case 'c':
						result1 = num11 * num22;
						expression1 = $"{num11}*{num22}={result1}";
						break;
				}
				Console.WriteLine(expression1);
				Console.WriteLine(expression1.Length);
			}
		}
	}
}