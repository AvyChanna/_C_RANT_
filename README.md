# _C_Rant_
A devRant API wrapper for C.

## Using _C_Rant_

To access devRant simply create a new `DevRant` object:

```
DevRant devRant = new DevRant();
```

The `DevRant` class itself can be used to get specific rants and users.

```
// Get a specific rant.
CommentedRant rant = devRant.getRant(686001);

// Get a user by username.
User me = devRant.getUser("LucaScorpion");
```

The `DevRant` class contains 2 methods for getting to specific parts of the api.
First, `getFeed()` which returns a `DevRantFeed` object.
This is used to access the rant and collab feeds.

```
// Get the 10 latest rants.
List<Rant> recent = devRant.getFeed().getRants(Sort.RECENT, 10, 0);

// Get the 10 best stories.
List<Rant> stories = devRant.getFeed().getStories(Sort.TOP, 0);

// Get 10 collabs.
List<Collab> collabs = devRant.getFeed().getCollabs(10);
```

Second, `getAuth()` which returns a `DevRantAuth` object, which is used to access user functionality.
Note that a user needs to be logged in before this can be accessed.

```
// Log in to devRant.
char[] password = "<password>".toCharArray();
devRant.login("<username>", password);

// Upvote a rant.
devRant.getAuth().voteRant(832125, Vote.UP);

// Clear the vote on a comment.
devRant.getAuth().voteComment(832169, Vote.NONE);

// Log out to clear the token.
devRant.logout();
```
