
# Bank Management System

## Project Description
This project is a basic **Bank Management System** built in C. The system allows you to manage multiple bank accounts by providing functionalities such as adding new accounts, editing details, processing transactions, and sorting account information. The system includes a menu interface for ease of use.

## Features
- **New Account Creation**: Add a new client with personal and financial details.
- **View List**: Display a list of all clients with their key information.
- **Edit Account**: Modify account details such as address or phone number.
- **Transactions**: Deposit or withdraw money from an account.
- **Erase Account**: Permanently delete an account.
- **View Account**: Check full details of a specific account.
- **Search Account**: Search for an account by name.
- **Sort Accounts**: Sort accounts by client name alphabetically.

## Technologies Used
- **Language**: C
- **Libraries**: 
  - `stdio.h` for input/output
  - `conio.h` for console input/output
  - `string.h` for string manipulation

## Files
- `main.c`: Contains the code for the bank management system.

## Setup and Execution
1. Clone the repository.
2. Compile the `main.c` file using a C compiler.
   ```bash
   gcc main.c -o bank_management_system
   ```
3. Run the executable:
   ```bash
   ./bank_management_system
   ```

## Usage
1. Enter the system using the default password: `1234`.
2. Choose options from the menu to create, view, edit, transact, or delete accounts.
3. Follow the on-screen prompts to perform operations.

### Menu Options:
- **1**: Create a new account.
- **2**: View all accounts.
- **3**: Edit account details.
- **4**: Perform transactions (deposit or withdraw).
- **5**: Delete an account.
- **6**: View a specific account.
- **7**: Search for an account by name.
- **8**: Sort and display accounts by name.

## Example Clients (Pre-loaded)
- **Names**: Islam, Ahmed, Hussein, Antonius, Magdy
- **Birth Dates**: 12/4/2002, 2/7/2006, etc.
- **National IDs**: 12345678912340, 98765432101598, etc.
- **Phone Numbers**: 703-636-2355, 716-807-9387, etc.
- **Deposit Types**: Saving (1), Current (2), Investment (3)
- **Initial Balances**: $1000, $1500, $500, etc.

## Contributions
Contributions to the project are welcome. Feel free to open issues or submit pull requests.

## License
This project is licensed under the MIT License.

