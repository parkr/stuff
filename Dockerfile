FROM ruby:3.2

ENV LC_ALL=C.UTF-8 LANG=C.UTF-8 LANGUAGE=C.UTF-8

WORKDIR /srv/app
COPY Gemfile* ./
RUN gem install bundler && bundle install --jobs 4

COPY . .

CMD [ "/bin/bash" ]
