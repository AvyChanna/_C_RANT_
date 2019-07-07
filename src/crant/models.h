#ifndef _C_RANT_MODELS_H_
#define _C_RANT_MODELS_H_

typedef struct{
	char*	url;
	int		width;
	int		height;
}ImageModel;

typedef struct{
	int			id;
	char*		text;
	int			num_upvotes;
	int			num_downvotes;
	int			score;
	int			created_time;
	ImageModel	attached_image;
	int			num_comments;
	char**		tags;
	int			user_id;
	char*		user_username;
	int			user_score;
}RantModel;

typedef struct{
	int		id;
	int		rant_id;
	char*	body;
	int		num_upvotes;
	int		num_downvotes;
	int		score;
	int		created_time;
	int		user_id;
	char*	user_username;
	int		user_score;
}CommentModel;

typedef struct{
	RantModel*	rants;
	RantModel*	upved;
	CommentModel*	comments;
	RantModel*	favorites;
}ContentModel;

typedef struct{
	ContentModel content;
}content;

typedef struct{
	char*	username;
	int		score;
	char*	about;
	char*	location;
	int		created_time;
	char*	skills;
	char*	github;
	content content;
}UserModel;

typedef struct{
	int		id;
	char*	type;
	char*	headline;
	char*	body;
	char*	footer;
	int		height;
	char*	action;
}NewsModel;

typedef struct{
	bool		success;
	char*		error;
	RantModel*	rants;
	char*		settings;
	char*		set;
	int		wrw;
	NewsModel	news;
}RantsResponse;

typedef struct{
	bool			success;
	char*			error;
	RantModel		rant;
	CommentModel*	comments;
}RantResponse;

typedef struct{
	bool		success;
	char*		error;
	RantModel*	results;
}SearchResponse;

typedef struct GetUserIdResponse{
	bool	success;
	char*	error;
	int		user_id;
}GetUserIdResponse;

typedef struct UserResponse {
	bool		success;
	char*		error;
	UserModel	profile;
}UserResponse;

#endif // _C_RANT_MODELS_H_
