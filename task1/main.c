#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int x;
    int y;
} point_t;

typedef struct
{
    char name[50];
    int num_points;
    point_t *points;
} polygon_t;

int main()
{
    FILE *file = fopen("polygons.txt", "r");
    if (!file)
    {
        printf("Failed to open file");
        return 0;
    }

    polygon_t *polygons = NULL;
    int polygon_count = 0;
    char line[256];

    while (fgets(line, sizeof(line), file))
    {
        polygons = realloc(polygons, (polygon_count + 1) * sizeof(polygon_t));
        if (!polygons)
        {
            printf("Failed to allocate memory for polygons");
            fclose(file);
            return 0;
        }

        line[strcspn(line, "\n")] = 0;
        strcpy(polygons[polygon_count].name, line);

        if (fgets(line, sizeof(line), file) == NULL)
        {
            printf("Failed to read number of points");
            free(polygons);
            fclose(file);
            return 0;
        }
        polygons[polygon_count].num_points = atoi(line);

        polygons[polygon_count].points = malloc(polygons[polygon_count].num_points * sizeof(point_t));
        if (!polygons[polygon_count].points)
        {
            printf("Failed to allocate memory for points");
            free(polygons);
            fclose(file);
            return 0;
        }

        for (int i = 0; i < polygons[polygon_count].num_points; i++)
        {
            if (fgets(line, sizeof(line), file) == NULL)
            {
                printf("Failed to read point coordinates");
                free(polygons[polygon_count].points);
                free(polygons);
                fclose(file);
                return 0;
            }
            sscanf(line, "%d %d", &polygons[polygon_count].points[i].x, &polygons[polygon_count].points[i].y);
        }

        polygon_count++;
    }

    fclose(file);

    for (int i = 0; i < polygon_count; i++)
    {
        printf("Polygon: %s\n", polygons[i].name);
        printf("Points: ");
        for (int j = 0; j < polygons[i].num_points; j++)
        {
            printf("(%d, %d)", polygons[i].points[j].x, polygons[i].points[j].y);
            if (j < polygons[i].num_points - 1)
            {
                printf(", ");
            }
        }
        printf("\n");
        free(polygons[i].points);
    }

    free(polygons);
    return 1;
}