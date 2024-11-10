using System;
namespace STL
{
	internal class Program
	{
		static void Main(string[] args)
		{
			string word = Console.ReadLine();
			string sentence = Console.ReadLine();
			string new_word = word.ToLower();
			string new_sentence = sentence.ToLower();
			var arr = new_sentence.Split(" ");
			int count = 0;
			foreach (var item in arr)
			{
				if(item == new_word)
				{
					count++;
				}
			}
			if (count > 0)
			{
				int index;
				string new_word1 = " " + new_word + " ";
				string new_word2 = " " + new_word;
				int index1 = new_sentence.IndexOf(new_word1);
				int index2 = new_sentence.IndexOf(new_word2);
				index = (index1 == -1) ? index2 + 1: index1 + 1;
				Console.WriteLine($"{count} {index}");
			}
			else
			{
				Console.WriteLine(-1);
			}
		}
	}
}
