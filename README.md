## RSA Factoring Challenge 

![alt text](https://saswtrust.com/wp-content/uploads/2021/03/Screenshot-2021-03-14-at-15.00.02-1536x505.png)

- HTTPS uses Secure Socket Layer to encrypt data that is transferred between client and server. SSL uses the RSA algorithm, an asymmetric encryption technology. The precise details of how the algorithm works is complex, but basically it leverages the fact that whilst multiplying two large prime numbers together is easy, factoring the result back into the constituent primes is very, very hard. How all SSL/RSA encryption works is:

- The server generates two large prime numbers, and multiplies them together. This is called the "public key". This key is made available to any client which wishes to transmit data securely to the server. The client uses this "public key" to encrypt data it wishes to send. Now because this is an asymmetric algorithm, the public key cannot be used to decrypt the transmitted data, only encrypt it. In order to decrypt, you need the original prime numbers, and only the server has these (the "private key"). On receiving the encrypted data, the server uses its private key to decrypt the transmission.

- In the case of you browsing the web, your browser gives the server its public key. The server uses this key to encrypt data to be sent to your browser, which then uses its private key to decrypt.

- So yes all data transmitted to/from server over HTTPs is encrypted  and encrypted well. Typical SSL implementations use 128 or 256 digits for their keys. To break this you need a truly vast amount of computing resources.

## Tasks :page_with_curl:

* **0. Factorize all the things!**
Factorize as many numbers as possible into a product of two smaller numbers.

- Usage: factors <file>
    - where <file> is a file containing natural numbers to factor.
    - One number per line
    - You can assume that all lines will be valid natural numbers greater than 1
    - You can assume that there will be no empy line, and no space before and after the valid number
    - The file will always end with a new line
- Output format: n=p*q
    - one factorization per line
    - p and q don’t have to be prime numbers
    - See example
- You can work on the numbers of the file in the order of your choice
- Your program should run without any dependency: You will not be able to install anything on the machine we will run your program on
- Time limit: Your program will be killed after 5 seconds if it hasn’t finish
- Push all your scripts, source code, etc… to your repository
    - we will only run your executable factors

* **1. RSA Factoring Challenge**
RSA Laboratories states that: for each RSA number `n`, there exist prime numbers `p` and `q` such that

`n = p × q`. The problem is to find these two primes, given only `n`.

This task is the same as task 0, except:
- p and q are always prime numbers
- There is only one number in the files
How far can you go in less than 5 seconds?

- Read: [RSA Factoring Challenge](https://en.wikipedia.org/wiki/RSA_Factoring_Challenge)

## Author

👤 **Eki Victory**

- GitHub: [@ekivictory1](https://github.com/ekivictory1)
- Twitter: [@victory_eki](https://twitter.com/victory_eki)
- LinkedIn: [LinkedIn](https://www.linkedin.com/in/eki-victory-371263134)

**Victory @ ALX software engineering programme 2022.**
## Show your support

Give a ⭐️ if you like this project!
