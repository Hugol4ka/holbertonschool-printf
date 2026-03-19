```mermaid
graph TD
    A[Start _printf] --> B{format[i] == '\0'?}
    B -- Yes --> C[Return Total Count]
    B -- No --> D{format[i] == '%'}
    
    D -- No --> E[Write char to stdout]
    E --> F[Total Count++]
    F --> G[i++]
    G --> B

    D -- Yes --> H{Check format[i+1]}
    H -- 'c' --> I[Call print_char]
    H -- 's' --> J[Call print_string]
    H -- '%' --> K[Write '%']
    H -- '\0' --> L[Return -1]
    
    I --> M[Total Count += return]
    J --> M
    K --> M
    M --> N[i += 2]
    N --> B