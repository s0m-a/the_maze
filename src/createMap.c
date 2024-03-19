
#include "../main.h"

/**
 * create_world - creates 2d world 
 * @input_num:integer representing the number of input level files
 * @level_files:arr of str with the filenames of the input
 * Return: memory allocated or NULL
 **/

attribute *create_world(int input_num, char *level_files[])
{
	attribute atrr = {NULL, 0, {0, 0}, {2, 8}, {1, 0}, {0, 0.5} };
	attribute *mem;
	int i, start;

	mem = malloc(sizeof(attribute) * (input_num - 1));
	if (mem == NULL)
		return (NULL);
	start = 0;
	// Iterate through input level files
	for (i = 1; i < input_num; i++, start++)
	{
		// Create map for current map
		atrr.map = create_map(level_files[i], &atrr.play,
				       &atrr.height);
		if (atrr.map == NULL)
			return (NULL);
		// Store attribute values in memory array
		mem[start] = atrr;
	}
	return (mem);
}

/**
 * count_char - Counts a given string
 * @line:str to count
 * Return:num of line
 **/
size_t count_char(char *line)
{
	size_t count = 0;
	while (line[count] != '\0')
		count++;
	return (count);
}


/**
 * count_line - Get the number of lines from a file
 * @str: The path to the file
 * Return: The number of lines found in the file, 0 for failure
 **/

size_t count_line(char *str)
{
	/*file to be read*/
	FILE *mfile;
	char *store = NULL;
	size_t lines = 0;
	//checks length of line
	size_t size = 0;
	ssize_t checked;
	mfile = fopen(str, "r");
	if (mfile == NULL)
	{
		fprintf(stderr, "File not found\n");
		return (0);
	}
	while ((checked = getline(&store, &size, mfile)) != -1)
	{
		lines++;
	}
	fclose(mfile);
	free(store);
	return (lines);
}


/**
 * draw_grid - Plots the  points in the maze
 * @mazeMap: The 2D array map
 * @player: player's position in the maze
 * @win: The x/y cooridinates of the win square
 * @curPos: The current character in the line being read
 * @maze_line: The line in the maze currently being created
 * @line: The line being read from the file
 **/
void draw_grid(char **mazeMap, DoubleStruct *play, size_t curPos,
		      size_t currLine, char *line)
{
	if (line[curPos] == '@')
	{
		// Update player's position
		play->y = curPos;
		play->x = currLine;
		// Set player's position in maze map
		mazeMap[currLine][curPos] = '0';
	}
	else
	{
		mazeMap[currLine][curPos] = line[curPos];
	}
}

/**
 * create_map - Create a 2D array for the map of the maze
 * @file_string: Path to the file containing the representation of the map
 * @play: Player x/y position
 * @win: The x/y cooridinate of the winning space
 * @hight: The height of the 2D array
 * Return: char ** to a representation of the map, NULL if it fails
 **/
char **create_map(char *file_string, DoubleStruct *play, size_t *hight)
{
	FILE *maze_file;
	char **maze, *line = NULL;
	ssize_t read = 0;
	size_t line_count, maze_line, char_count, cur_char, bufsize;
	maze_line = 0;
	line_count = count_line(file_string);
	*hight = line_count;
	// Check if the file is empty
	if (line_count == 0)
		return (NULL);
	// Allocate memory for the maze array
	maze = malloc(sizeof(int *) * line_count);
	if (maze == NULL)
		return (NULL);

	maze_file = fopen(file_string, "r");
	if (maze_file == NULL)
		return (NULL);
	
	// Read each line from the file
	read = getline(&line, &bufsize, maze_file);
	while (read != -1)
	{
		// Count the number of characters in the line
		char_count = count_char(line);
		// Allocate memory for the current line of the maze
		maze[maze_line] = malloc(sizeof(char) * char_count + 1);
		if (maze == NULL)
			return (NULL);
		
		// Process each character of the line
		for (cur_char = 0; cur_char < char_count; cur_char++)
		{
			/*function that process the character*/
			draw_grid(maze, play, cur_char, maze_line, line);
		}

		// Move to the next line
		maze_line++;
		read = getline(&line, &bufsize, maze_file);
	}
	//close file and deallocate memory
	fclose(maze_file);
	free(line);
	return (maze);
}
