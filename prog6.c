#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) 
{
    int rank;
    int data_send;
    int data_recv;

    // Initialize MPI
    MPI_Init(&argc, &argv);

    // Get the process rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Each process sends its rank
    data_send = rank;

    if (rank == 0) 
    {
        // Process 0 sends data to Process 1
        MPI_Send(&data_send, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Process 0 receives data from Process 1
        MPI_Recv(&data_recv, 1, MPI_INT, 1, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Process %d received %d\n", rank, data_recv);
    }
    else if (rank == 1) 
    {
        // Process 1 sends data to Process 0
        MPI_Send(&data_send, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);

        // Process 1 receives data from Process 0
        MPI_Recv(&data_recv, 1, MPI_INT, 0, 0,
                 MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        printf("Process %d received %d\n", rank, data_recv);
    }

    // Finalize MPI
    MPI_Finalize();

    return 0;
}
