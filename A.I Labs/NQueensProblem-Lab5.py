class NQueens:
    def __init__(self, size):
        # Store the puzzle (problem) size and the number of valid solutions
        self.size = size
        self.solutions = 0
        self.solve()

    def solve(self):

        # Solve the n queens puzzle and print the number of solutions
        positions = [-1] * self.size
        self.put_queen(positions, 0)
        print("Found", self.solutions, "solutions to solve this problem!.\n===========================================")

    def put_queen(self, positions, target_row):

        # Try to place a queen on target_row by checking all N possible cases.
        # If a valid place is found the function calls itself trying to place a queen on the next row until all N queens are placed on the NxN board.
        # Base (stop) case - all N rows are occupied
        if target_row == self.size:
            self.show_short_board(positions)
            self.show_full_board(positions)
            self.solutions += 1
        else:
            # For all N columns positions try to place a queen
            for column in range(self.size):
                if self.check_place(positions, target_row, column):
                    positions[target_row] = column
                    self.put_queen(positions, target_row + 1)

    def check_place(self, positions, ocuppied_rows, column):

        # Check if a given position is under attack from any of the previously placed queens (check column and diagonal positions)

        for i in range(ocuppied_rows):
            if positions[i] == column or positions[i] - i == column - ocuppied_rows or positions[i] + i == column + ocuppied_rows:
                return False
        return True

    def show_full_board(self, positions):
        # Show the full NxN board
        for row in range(self.size):
            line = ""
            for column in range(self.size):
                if positions[row] == column:
                    line += "Q " 
                    # where Q == Queen
                else:
                    line += "* "
                    # where * == black empty box where none of the Queen can be placed
            print(line)
        print("\n")

    def show_short_board(self, positions):
        # Show the queens positions on the board in compressed form, each number represent the occupied column position in the corresponding row.

        line = ""
        for i in range(self.size):
            line += str(positions[i]) + " "
        print(line)
# class Nqueens ends here

def main():
    # Initialize and solve the n queens puzzle
    NQueens(8) # as in book, it is '8' queens problem


if __name__ == "__main__":
    main()
