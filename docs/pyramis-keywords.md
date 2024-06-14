### 📖 Components of a Pyramis Specification
<details>
<summary> <strong>Interface file</strong></summary>
  The interface file is a json file that describes the architecture of your multi-system in terms of individual nodes and their <ins>interface descriptions</ins>.
  An interface description consists of the following keys:
  ![image](https://github.com/armaanchowfin/pyramis/assets/57800921/53532a67-1c07-4933-83ac-acc5cc17ed12)

</details>

<details>
<summary> <strong>Processing File</strong></summary>
</details>

<details>
<summary> <strong>User-Defined Functions (UDF) File</strong></summary>
</details>

### 📖 Requirements for compilation to executable NF

Pyramis keywords can flexibly represent key aspects of most multi-tier systems. However, to compile to a working implementation, certain constraints have to be imposed on the inputs and outputs.
  
<details>
<summary> <strong>Well-Defined L-7 protocol library</strong></summary>
  Pyramis supports multitier systems using the NGAP and HTTP L-7 protocols out of the box. However, rolling your own application-layer protocol would have to meet certain requirements: 

- Valid messages for custom protocols must be implemented as complete C/C++ structs. These files may be stored in a `utils` directory in the your root folder.
- HTTP messages must represent and access their payload strings as attributes of nlohmann::json objects. We provide an HTTP library for this purpose.
- All char arrays are interpreted as C++ `std::vector<char>`. Strings, if any, must be null-terminated.
</details>

<details>
<summary> <strong>Platform-file + Processing-file architecture</strong></summary>
  Where a platform file triggers kernel networking actions, and the processing file performs user-level message-processing actions

- In the current implementation, a C++ user-level processing file is generated from the Pyramis specification.
- In the current implementation, a multithreaded, asynchronous epoll-based platform.cpp file is generated that declares an entry point into the user-level processing code.
</details>

<details>
<summary> <strong>Notion of procedure key</strong></summary>
  The NF must generate a unique procedure key for each instance of procedure. Procedure may be simple (login request-response) or complex (SMF session-establishment). Complexity arises due to the requirement of demultiplexing messages received at a single interface to the correct message handler. The notion of "key" and its supporting `fd_to_key_map` and `key_to_fd_map` are implementation-specific constructs that enable this message demultiplexing.

- `procedure_key` is used by the NF application to maintain a synchronous message-processing flow despite asynchronous message ingress at an NF
- A single NF independently initiates procedure requests.
  </details>