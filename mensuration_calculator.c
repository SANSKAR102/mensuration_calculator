#include <stdio.h>
#include <math.h>

 
float area_circle(float radius);
float circumference_circle(float radius);
float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);
float area_triangle(float base, float height);
float perimeter_triangle(float a, float b, float c);
void clear_input_buffer();

int main() {
    int choice;
    float a, b, c;

    while (1) {
        printf("\n===== Mensuration Calculator =====\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter radius: ");
                if (scanf("%f", &a) != 1 || a <= 0) {
                    printf("Invalid radius.\n");
                    clear_input_buffer();
                    break;
                }
                printf("Area: %.2f\n", area_circle(a));
                printf("Circumference: %.2f\n", circumference_circle(a));
                break;

            case 2:
                printf("Enter length and width: ");
                if (scanf("%f %f", &a, &b) != 2 || a <= 0 || b <= 0) {
                    printf("Invalid dimensions.\n");
                    clear_input_buffer();
                    break;
                }
                printf("Area: %.2f\n", area_rectangle(a, b));
                printf("Perimeter: %.2f\n", perimeter_rectangle(a, b));
                break;

            case 3:
                printf("Enter sides a, b, c: ");
                if (scanf("%f %f %f", &a, &b, &c) != 3 || a <= 0 || b <= 0 || c <= 0 ||
                    (a + b <= c || a + c <= b || b + c <= a)) {
                    printf("Invalid triangle sides.\n");
                    clear_input_buffer();
                    break;
                }
                float s = (a + b + c) / 2;
                printf("Area: %.2f\n", sqrt(s * (s - a) * (s - b) * (s - c)));
                printf("Perimeter: %.2f\n", perimeter_triangle(a, b, c));
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

 
float area_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

 
float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

 
float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}

 
void clear_input_buffer() {
    while (getchar() != '\n');
}
