// Pig Latin.
class  Piglatin{
static boolean isVowel(char c) {
	return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
			c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

static String pigLatin(String s) {

	// the index of the first vowel is stored.
	int len = s.length();
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (isVowel(s.charAt(i))) {
		index = i;
		break;
	}
	}

	// Pig Latin is possible only if vowels
	// is present
	if (index == -1)
		return "-1";

	// Take all characters after index (including
	// index). Append all characters which are before
	// index. Finally append "ay"
	return s.substring(index) +
		s.substring(0, index) + "ay";
}

// Driver code
public static void main(String[] args) {
	String str = pigLatin("graphic");
	if (str == "-1")
		System.out.print("No vowels found." +
						"Pig Latin not possible");
	
	else
		System.out.print(str);
}
}
