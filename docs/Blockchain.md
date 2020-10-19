# Blockchain

As this is a decentralised network, there needs to be a way for messages and invites between users when they are not directly connected to one another or they are offline.
Blockchain allows us to hold this information across a range of devices whilst keeping the data secure and prevent tampering

### How data is stored in the blockchain
When a user joins the network, they create a public key which is shared on the blockchain along with the user's username. 
Their public key is then accessible to all other users who can use it to send encrypted messages to the user when they are not connected on the network.
This can include game invites and messages provided that the information sent is no more then 1MB. 
The blockchain will also only support plaintext messages to increase performance and reduce overhead.

### Background processes
The API will require a background process on a machine to monitor for messages related to the user and to update its copy of the blockchain ledger.
