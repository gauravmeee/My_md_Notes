# [What is Sentiment Analysis?](https://www.youtube.com/watch?v=5HQCNAsSO-s "What is Sentiment Analysis?")

Sentimental Analysis -> NLP

**NLP**
- Rule Based : Lexicons
- ML Based 

**Machine Learnings**
- Linear Regression
- Naive Bayes
- Support Vector Machine (SVM)

Polarity : Extremely Negative, Negative, Neutral, Positive, Extremely Positive

Sentiment Analysis
- Fine Grained - Polarity (0-100)
- (Aspect Based Sentiment Analysis) ABSA
- Emotion Detection
- 

# [What is NLP (Natural Language Processing)?](https://www.youtube.com/watch?v=fLvJ8VdHLA0&t=509s "What is NLP (Natural Language Processing)?")

**NLP**
- Unstructured ---(NLU)---> Structured
- Structured ---(NLG)---> Unstructured

NLU - Natural Language Understanding
NLG - Natural Language Generation

Unstructured:
`ADD Eggs and Milk to my Shopping List`

Structured:
```
<Shopping List>
<Item> Eggs </>
<Item> Milk </>
</>
```

**Steps in NLP:**
- Input : unstructured Language
1. Tokenization
2. Stemming / Lemmatization
3. Part of Speech Tagging
4. Named Entity Recognition(NEG)
# [Sentiment Analysis In 10 Minutes | Sentiment Analysis Using Python | Great Learning](https://www.youtube.com/watch?v=Ao4-ZIPOGJI "Sentiment Analysis In 10 Minutes | Sentiment Analysis Using Python | Great Learning")

# [Sentiment Analysis Project with LLM | Chatgpt & Gemini API](https://www.youtube.com/watch?v=3z0a3Ymwj1k&t=140s "Sentiment Analysis Project with LLM | Chatgpt & Gemini API")


# [Indian Politics Tweets EDA and Sentiment Analysis](https://www.kaggle.com/code/adritpal08/indian-politics-tweets-eda-and-sentiment-analysis/notebook#%F0%9F%9B%A0%EF%B8%8FInstalling-Necessary-Libraries)

**EDA:** EDA stands for **Exploratory Data Analysis**. It is a crucial step in data analysis that involves examining datasets to summarize their main characteristics, often using visualizations and descriptive statistics. The goal of EDA is to understand the data, identify patterns, spot anomalies, and test hypotheses before applying more complex modeling or analysis techniques.

```python
# Import necessary libraries
import pandas as pd
import re
from nltk.corpus import stopwords
from better_profanity import profanity
from textblob import TextBlob

# Load the data
tweet = 'Political_tweets_data1.csv'
df = pd.read_csv(tweet)

# Initial data processing
df['Original_Tweet'] = df['Tweet']
df['DateTime'] = df['Date']
df = df.drop('Date', axis=1)
df['DateTime'] = df['DateTime'].astype(str).apply(lambda x: x.split('+')[0])

# Convert 'DateTime' column to datetime format and handle invalid values
df['DateTime'] = pd.to_datetime(df['DateTime'], errors='coerce', format='%Y-%m-%d %H:%M:%S').fillna(pd.Timestamp('1900-01-01'))

# Extract date-related information
df['date'] = df.DateTime.apply(lambda x: x.date())
df['month'] = df.DateTime.apply(lambda x: x.month)
df['year'] = df.DateTime.apply(lambda x: x.year)
df['hour'] = df.DateTime.apply(lambda x: x.hour)

# Ensure NLTK stopwords are downloaded
import nltk
nltk.download('stopwords')
stop_words = set(stopwords.words('english'))

# Define the function to clean tweets
def clean_tweet(tweet):
    # Convert to lower case
    tweet = tweet.lower()
    
    # Censor profanity
    profanity.load_censor_words()
    tweet = profanity.censor(tweet)
    
    # Remove Twitter handles
    tweet = re.sub('@[^\s]+', '', tweet)
    
    # Remove hashtags
    tweet = re.sub(r'\B#\S+', '', tweet)
    
    # Remove URLs
    tweet = re.sub(r"http\S+", "", tweet)
    
    # Remove non-word characters
    tweet = re.sub(r'\W', ' ', tweet)
    
    # Remove single characters (except 'a' and 'I')
    tweet = re.sub(r'\s+[a-hj-z]\s+', ' ', tweet)
    tweet = re.sub(r'\s+i\s+', ' I ', tweet)
    tweet = re.sub(r'\s+a\s+', ' a ', tweet)
    
    # Replace multiple spaces with a single space
    tweet = re.sub(r'\s+', ' ', tweet, flags=re.I)
    
    # Remove stop words
    tweet = ' '.join([word for word in tweet.split() if word not in stop_words])
    
    return tweet

# Clean the tweets
df['Tweet'] = df['Tweet'].apply(clean_tweet)

# Define the sentiment objects using TextBlob
sentiment_objects = [TextBlob(tweet) for tweet in df['Tweet']]

# Extract polarity values and assign sentiment labels
df['Polarity'] = [tweet.sentiment.polarity for tweet in sentiment_objects]
df['Sentiment'] = df['Polarity'].apply(lambda x: 'Positive' if x > 0 else 'Negative' if x < 0 else 'Neutral')

# Display the processed DataFrame
print(df.head())
```
# [political sentiment analysis using twitter data by rohit kaliyar](https://www.youtube.com/watch?v=L4DIW6fz5XY&t=639s "political sentiment analysis using twitter data by rohit  kaliyar")

# [Twitter sentiment analysis introduction | By Viswateja](https://www.youtube.com/watch?v=G0fIxh2yTbI&t=376s "Twitter sentiment analysis introduction  | By Viswateja")
  


