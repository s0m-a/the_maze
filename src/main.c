#include "../main.h"

/**
 * main - main function
 * @argc: num of arguments passed
 * @argv: array of arg passed
 * Return: 1 if failure, 0 if successful exit
 **/
int main(int argc, char *argv[])
{
	int x;
	int input_num;
	SDL_Instance instance;
	keys key = {0, 0, 0, 0};
	attribute *stage;

	x = 0;
	input_num = argc;
	if (input_num < 2)
	{
		printf("level not found \n");
		return (1);
	}
		
	stage = create_world(argc, argv);
	if (stage == NULL)
		return (1);
	if (init_instance(&instance) != 0)
		return (1);
	x = 0;
	/*game loop*/
	while (1)
	{
		if (read_key_input(&key))
		{
			freeMemory(instance, stage[x].map, stage[x].height);
			break;
		}
		//rotation and speed 
		movement(key, &stage[x].plane, &stage[x].dir, &stage[x].play,
			 stage[x].map);

		create(instance, stage[x].map, stage[x].play, stage[x].dir,
		     stage[x].plane);
	}
	close_SDL(instance);
	return (0);
}
