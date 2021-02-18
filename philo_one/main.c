
int main(int argc, char **argv)
{
    int     num_phil;
    int     t_eat,

    if (argc < 5)
    {
        write(1, "too few arguments\n", strlen("too few arguments\n"));
        return (-1);
    }
    if (argc > 6)
    {
        write(1, "too many arguments\n", strlen("too many arguments\n"));
        return (-1);
    }
    num_phil = atoi(argv[1]);
    printf("philos: %i\n", num_phil);
}