# Python Program to convert prefix to Infix
def prefixToInfix(prefix):
	stack = []
	
	# read prefix in reverse order
	i = len(prefix) - 1
	while i >= 0:
		if not isOperator(prefix[i]):
			
			# symbol is operand
			stack.append(prefix[i])
			i -= 1
		else:
		
			# symbol is operator
			str = "(" + stack.pop() + prefix[i] + stack.pop() + ")"
			stack.append(str)
			i -= 1
	
	return stack.pop()

def isOperator(c):
	if c == "*" or c == "+" or c == "-" or c == "/" or c == "^" or c == "(" or c == ")":
		return True
	else:
		return False

# Driver code
if __name__=="__main__":
	str = "*-A/BC-/AKL"
	print(prefixToInfix(str))
	
# This code is contributed by avishekarora
