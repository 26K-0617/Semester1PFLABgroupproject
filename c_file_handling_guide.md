# Comprehensive Guide to File Handling in C

File I/O (Input/Output) allows C programs to persist data across execution cycles by reading from and writing to external storage files.

---

## Topic 1: Standard File Management & Basic Operations

In C, files are accessed and managed using a stream represented by a pointer to a system structure: `FILE *`.

### 1. Key File Operations & Functions

| Action | Function Signature | Description |
| :--- | :--- | :--- |
| **Open File** | `FILE *fopen(const char *filename, const char *mode);` | Opens a file stream with a specific access mode. Returns `NULL` on failure. |
| **Close File** | `int fclose(FILE *stream);` | Flushes stream buffer and closes the file. Returns `0` on success. |
| **Char I/O** | `fgetc(FILE *fp)` / `fputc(int c, FILE *fp)` | Reads or writes a single character. |
| **Formatted I/O**| `fscanf(fp, format, ...)` / `fprintf(fp, format, ...)` | Reads or writes formatted data (similar to `scanf`/`printf`). |
| **String I/O** | `fgets(char *str, int n, FILE *fp)` / `fputs(const char *str, FILE *fp)` | Reads or writes line-by-line safely. |

---

### 2. File Opening Modes (`fopen` modes)

| Mode | Type | Behavior if File Exists | Behavior if File Does NOT Exist |
| :--- | :--- | :--- | :--- |
| `"r"` | Read | Opens for reading from start | Returns `NULL` (Error) |
| `"w"` | Write | Overwrites / Truncates to 0 bytes | Creates a new file |
| `"a"` | Append | Writes to the end of file | Creates a new file |
| `"r+"`| Read/Write | Opens for reading/writing at start | Returns `NULL` (Error) |
| `"w+"`| Read/Write | Overwrites / Truncates to 0 bytes | Creates a new file |
| `"a+"`| Read/Write | Reads from start, appends to end | Creates a new file |

*Note: Append `"b"` to any mode (e.g., `"rb"`, `"wb"`) to handle binary files explicitly.*

---

### 3. Practical Example: Text File Workflow

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Open file for writing
    FILE *fptr = fopen("user_log.txt", "w");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 2. Write data to file
    fprintf(fptr, "User Log ID: %d\nStatus: %s\n", 101, "Active");
    fclose(fptr); // Always close files when done!

    // 3. Open file for reading
    fptr = fopen("user_log.txt", "r");
    if (fptr == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // 4. Read contents line by line
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fptr);
    return 0;
}
```

---

## Topic 2: Advanced Binary File I/O & File Positioning

Binary operations bypass formatting conversions, writing memory contents directly to disk. This is ideal for saving structured data (e.g., `struct`).

### 1. Binary Block Read / Write

```c
// Writes 'count' elements of 'size' bytes from buffer to stream
size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);

// Reads 'count' elements of 'size' bytes from stream into buffer
size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
```

---

### 2. Random Access & File Pointer Manipulation

Normally, C reads or writes sequentially. You can jump directly to specific positions in a file using positioning functions:

* **`fseek(FILE *fp, long offset, int origin)`**: Moves the file position indicator.
  * `SEEK_SET`: Beginning of file.
  * `SEEK_CUR`: Current position of file pointer.
  * `SEEK_END`: End of file.
* **`ftell(FILE *fp)`**: Returns current byte offset of file pointer from start.
* **`rewind(FILE *fp)`**: Resets file pointer back to the beginning (`fseek(fp, 0, SEEK_SET)`).
* **`feof(FILE *fp)`**: Returns non-zero (true) if End-Of-File flag is reached.

---

### 3. Practical Example: Binary Struct Records with Seek

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[30];
    float score;
} Student;

int main() {
    Student s1 = {1, "Alice", 95.5f};
    Student s2 = {2, "Bob", 88.0f};

    // 1. Write binary structures to file
    FILE *fp = fopen("students.bin", "wb");
    if (!fp) return 1;

    fwrite(&s1, sizeof(Student), 1, fp);
    fwrite(&s2, sizeof(Student), 1, fp);
    fclose(fp);

    // 2. Read specific record directly using fseek
    fp = fopen("students.bin", "rb");
    if (!fp) return 1;

    Student temp;

    // Move file pointer directly to 2nd record (skip 1st struct)
    fseek(fp, 1 * sizeof(Student), SEEK_SET);
    fread(&temp, sizeof(Student), 1, fp);

    printf("Record #2 -> ID: %d, Name: %s, Score: %.1f\n", 
           temp.id, temp.name, temp.score);

    // Find current size of file in bytes
    fseek(fp, 0, SEEK_END);
    long totalSize = ftell(fp);
    printf("Total binary file size: %ld bytes\n", totalSize);

    fclose(fp);
    return 0;
}
```