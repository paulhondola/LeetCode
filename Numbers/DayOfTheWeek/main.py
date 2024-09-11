import datetime
class Solution:
	def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
	    # Create a date object from the given year, month, and day
	    date = datetime.date(year, month, day)
	    # Return the name of the day
		return date.strftime("%A")

# Create an instance of the Solution class
solution = Solution()
# Test the function with some example inputs
print(solution.dayOfTheWeek(31, 8, 2019))  # Output: Saturday
